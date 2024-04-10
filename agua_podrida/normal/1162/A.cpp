#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i <=b; i++)
#define F1(i,n) for(int i = 1; i<= n;i++)
#define F0(i,n) for(int i = 0; i< n;i++)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define  F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;

bool sirveComoCentro(vector<vi>& tablero, int i, int j, int k){
    //filas simetricas
    REP(x1,0,2*k-2) {
        REP(y1,0,2*k-2){
            int x2 = 2*i-x1;
            int y2 = y1;
            if(x2 >= 0 && x2 < 2*k-1 && tablero[x2][y2] != tablero[x1][y1] && tablero[x2][y2] != -1 && tablero[x1][y1] != -1)
                return false;
        }
    }
    //columnas simetricas
    REP(x1,0,2*k-2) {
        REP(y1,0,2*k-2){
            int x2 = x1;
            int y2 = 2*j-y1;
            if(y2 >= 0 && y2 < 2*k-1 && tablero[x2][y2] != tablero[x1][y1] && tablero[x2][y2] != -1 && tablero[x1][y1] != -1)
                return false;
        }
    }
    //los de afuera del rombo
    REP(x,0,2*k-2){
        REP(y,0,2*k-2){
            int x1 = 2*i-x;
            int y1 = y;
            int x2 = x;
            int y2 = 2*j-y;
            if(0<=x1 && x1 < 2*k-1 && 0<=y2 && y2 < 2*k-1 && tablero[x1][y1] != -1 && tablero[x2][y2] != -1 && tablero[x1][y1] != tablero[x2][y2])
                return false;
        }
    }
    return true;
}

void actualizarRes(int& res, int i, int j,int k){
    int nuevoK = abs(i-k+1) + abs(j-k+1) + k;
    res = min(nuevoK*nuevoK - k*k,res);
}

void a(){
    int t;
    cin>>t;
    REP(x,1,t){
        int k;
        cin>>k;
        vector<vi> tablero;
        vi fila(2*k-1,-1);
        REP(i,1,2*k-1) tablero.EB(fila);
        REP(i,0,2*k-2){
            for(int j = max(k-1-i,i-k+1); j < min(k+i,3*k-2-i);j += 2){
                cin>>tablero[i][j];
            }
        }
        int res = 1000000000;
        REP(i,0,2*k-2){
            REP(j,0,2*k-2){
                if(sirveComoCentro(tablero,i,j,k)) actualizarRes(res,i,j,k);
            }
        }
        cout<<"Case #"<<x<<": "<<res<<'\n';
    }
}

ll resolver(vi& tree, int instancia, vi& tol, int yaCompre, vector<vll>& dicc, int cantEq){
    if(dicc[instancia][yaCompre] == -1) {
        if (instancia >= cantEq / 2) {
            if (tol[(instancia - cantEq / 2) * 2] <= yaCompre && tol[(instancia - cantEq / 2) * 2 + 1] <= yaCompre)
                dicc[instancia][yaCompre] = 0;
            else if (tol[(instancia - cantEq / 2) * 2] <= yaCompre + 1 && tol[(instancia - cantEq / 2) * 2 + 1] <= yaCompre + 1)
                dicc[instancia][yaCompre] = tree[instancia];
            else
                REP(i, 0, yaCompre) dicc[instancia][i] = 2000000000;
        } else {
            dicc[instancia][yaCompre] = min(
                    resolver(tree, 2 * instancia, tol, yaCompre, dicc, cantEq) +
                    resolver(tree, 2 * instancia + 1, tol, yaCompre, dicc, cantEq),
                    resolver(tree, 2 * instancia, tol, yaCompre + 1, dicc, cantEq) +
                    resolver(tree, 2 * instancia + 1, tol, yaCompre + 1, dicc, cantEq) + tree[instancia]);
        }
    }
    return dicc[instancia][yaCompre];
}

void b(){
    int t;
    cin>>t;
    REP(x,1,t){
        int p;
        cin>>p;
        int cantEq = (int) pow(2,p);
        vi tree(cantEq);
        vi tol(cantEq);
        REP(i,0,cantEq-1) cin>>tol[i];
        reverse(tol.begin(),tol.end());
        REP(i,0,cantEq-1) tol[i] = p - tol[i];
        REP(i,1,cantEq-1) cin>>tree[cantEq-i];
        vector<vll> dicc;
        vll undef(p,-1);
        REP(i,1,cantEq){
            dicc.EB(undef);
        }
        ll res = resolver(tree,1,tol,0,dicc,cantEq);
        cout<<"Case #"<<x<<": "<<res<<'\n';
    }
}

bool hayBacteria(vector<vector<bool>>& grilla){
    REP(i,0,99){
        REP(j,0,99){
            if(grilla[i][j]) return true;
        }
    }
    return false;
}

void avanzar(vector<vector<bool>>& grilla){
    for(int i = 99; i > 0; i--){
        for(int j = 99; j > 0; j--){
            if(!grilla[i][j] && grilla[i-1][j] && grilla[i][j-1]) grilla[i][j] = true;
            else if(grilla[i][j] && !grilla[i-1][j] && !grilla[i][j-1]) grilla[i][j] = false;
        }
    }
    for(int i = 99; i > 0; i--){
        if(!grilla[i-1][0]) grilla[i][0] = false;
        if(!grilla[0][i-1]) grilla[0][i] = false;
    }
    grilla[0][0] = false;
}

void c(){
    int t;
    cin>>t;
    REP(x,1,t){
        int r;
        cin>>r;
        vector<bool> fila(100,false);
        vector<vector<bool>> grilla;
        REP(i,1,100){
            grilla.EB(fila);
        }
        REP(z,1,r){
            int x1, x2, y1, y2;
            cin>>x1>>y1>>x2>>y2;
            x1--;
            y1--;
            x2--;
            y2--;
            REP(i,x1,x2){
                REP(j,y1,y2){
                    grilla[i][j] = true;
                }
            }
        }
        int res = 0;
        while(hayBacteria(grilla)){
            avanzar(grilla);
            res++;
        }
        cout<<"Case #"<<x<<": "<<res<<'\n';
    }
}

void a1(){
    vector<vvi> aparecePos;
    vvi cincoVacios(5);
    F1(i,5) aparecePos.EB(cincoVacios);
    char aux;
    F0(i,119){
        cout<<5*i+1<<endl;
        cin>>aux;
        if(aux == 'A')
            aparecePos[1][0].PB(5*i+1);
        if(aux == 'B')
            aparecePos[1][1].PB(5*i+1);
        if(aux == 'C')
            aparecePos[1][2].PB(5*i+1);
        if(aux == 'D')
            aparecePos[1][3].PB(5*i+1);
        if(aux == 'E')
            aparecePos[1][4].PB(5*i+1);
    }
    vi permutacionQueFalta;
    F1(i,3){
        int falta = 0;
        F1(j,4){
            if(aparecePos[i][j].size() < aparecePos[i][falta].size()) falta = j;
        }
        permutacionQueFalta.EB(falta);
        F0(j,aparecePos[i][falta].size()){
            cout<<aparecePos[i][falta][j]+1<<endl;
            cin>>aux;
            if(aux == 'A')
                aparecePos[i+1][0].PB(aparecePos[i][falta][j]);
            if(aux == 'B')
                aparecePos[i+1][1].PB(aparecePos[i][falta][j]);
            if(aux == 'C')
                aparecePos[i+1][2].PB(aparecePos[i][falta][j]);
            if(aux == 'D')
                aparecePos[i+1][3].PB(aparecePos[i][falta][j]);
            if(aux == 'E')
                aparecePos[i+1][4].PB(aparecePos[i][falta][j]);
        }
    }
    int falta = 0;
    F1(j,4){
        if(aparecePos[4][j].size() < aparecePos[4][falta].size()) falta = j;
    }
    permutacionQueFalta.EB(falta);
    vector<bool> aparece(5,false);
    string res;
    F0(i,4){
        if(permutacionQueFalta[i] == 0)
            res.PB('A');
        if(permutacionQueFalta[i] == 1)
            res.PB('B');
        if(permutacionQueFalta[i] == 2)
            res.PB('C');
        if(permutacionQueFalta[i] == 3)
            res.PB('D');
        if(permutacionQueFalta[i] == 4)
            res.PB('E');
        aparece[permutacionQueFalta[i]] = true;
    }
    F0(i,5) {
        if (!aparece[i]) {
            if(i == 0)
                res.PB('A');
            if(i == 1)
                res.PB('B');
            if(i == 2)
                res.PB('C');
            if(i == 3)
                res.PB('D');
            if(i == 4)
                res.PB('E');
        }
    }
    cout<<res<<endl;
    cin>>aux;
}

void a2(){
    int n,h,m;
    cin>>n>>h>>m;
    vi alturas(n+1,h);
    F1(i,m){
        int l,r,x;
        cin>>l>>r>>x;
        REP(j,l,r) alturas[j] = min(alturas[j],x);
    }
    int res = 0;
    F1(i,n){
        res += alturas[i]*alturas[i];
    }
    cout<<res<<endl;
}

int main(){
    //freopen("../output.txt","w",stdout);
    a2();
    return 0;
}