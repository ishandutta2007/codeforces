#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i <=b; i++)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define  F first
#define S second
typedef long long ll;

void a() {
    int t;
    cin>>t;
    int p, q;
    int xi,yi;
    char di;
    REP(x,1,t){
        cin>>p>>q;
        vector<int> ys(q+1,0);
        vector<int> xs(q+1,0);
        REP(i,1,p){
            cin>>xi>>yi>>di;
            if(di == 'N')
                ys[yi+1]++;
            if(di == 'S'){
                ys[0]++;
                ys[yi]--;
            }
            if(di == 'E')
                xs[xi+1]++;
            if(di == 'W'){
                xs[0]++;
                xs[xi]--;
            }
        }
        int maxx = 0;
        REP(i,1,q){
            xs[i] += xs[i-1];
            if(xs[i] > xs[maxx])
                maxx = i;
        }
        int maxy = 0;
        REP(i,1,q){
            ys[i] += ys[i-1];
            if(ys[i] > ys[maxy])
                maxy = i;
        }
        cout<<"Case #"<<x<<": "<<maxx<< " "<< maxy<<'\n';
    }
}

void b(){
    int t;
    cin>>t;
    int w;
    cin>>w;
    while(t--){
        ll total;
        vector<ll> aux(2);
        vector<ll> hayDe(7);

        cout<<75<<endl;
        ll aux0;
        cin>>aux0;
        hayDe[2] = aux0>>37;
        hayDe[3] = (aux0 - (hayDe[2]<<37))>>25;
        ll b0 = aux0 % (1<<25);

        cout<<10<<endl;
        cin>>aux[1];
        aux[1] -= hayDe[2]<<5;
        aux[1] -= hayDe[3]<<3;
        hayDe[1] = aux[1]>>10;
        ll b1 = aux[1] % 1024;

        ll x4,x5,x6;
        for(x4 = 0; x4<=100;x4++) for(x5 = 0; x5<=100;x5++) for(x6 = 0; x6<=100;x6++)
            if((x4<<18) + (x5<<15) + (x6<<12) == b0 && (x4<<2)+(x5<<2)+(x6<<1) == b1)
                break;

        cout<<hayDe[1]<<" "<<hayDe[2]<<" "<<hayDe[3]<<" "<<x4<<" "<<x5<<" "<<x6<<endl;

        if(aux[0] == -1) return;
    }
}

int maxr(vector<int>& v, int l, int r){
    int res = 0;
    REP(i,l,r)
        res=max(res,v[i]);
    return res;
}

vector<vector<int>> procesarMaximo(vector<int> v){
    vector<vector<int>> res;
    res.PB(v);
    int tamano = 2;
    int nivel = 0;
    while(tamano <= v.size()){
        vector<int> esteNivel;
        REP(i,0,v.size()-tamano){
            esteNivel.PB(max(res[nivel][i],res[nivel][i+1]));
        }
        res.PB(esteNivel);
        tamano*=2;
        nivel++;
    }
    return res;
}

int maximoEnRango(vector<int>& tree, int a, int b){
    int n = tree.size()/2;
    a+=n;
    b+=n;
    int s = 0;
    while(a <= b) {
        if(a%2 == 1) s = max(s,tree[a++]);
        if(b%2 == 0) s = max(s,tree[b--]);
        a/=2;
        b/=2;
    }
    return s;
}

vector<int> segmentTreeMax(vector<int>& v){
    int n = v.size();
    vector<int> res(2*n);
    REP(i,0,n-1){
        res[n+i] = v[i];
    }
    for(int i = n-1; i > 0; i--){
        res[i] = max(res[2*i],res[2*i+1]);
    }
    return res;
}

void c(){
    int t;
    cin>>t;
    int n, k;
    REP(x,1,t){
        cin>>n>>k;
        vector<int> carlos(n);
        vector<int> delia(n);
        REP(i,0,n-1){
            cin>>carlos[i];
        }
        REP(i,0,n-1)
            cin>>delia[i];
        vector<int> carlosTree = segmentTreeMax(carlos);
        vector<int> deliaTree = segmentTreeMax(delia);
        int res = 0;
        REP(l,0,n-1){
            REP(r,l,n-1){
                if(abs(maximoEnRango(carlosTree,l,r) - maximoEnRango(deliaTree,l,r)) <= k)
                    res++;
            }
        }
        cout<<"Case #"<<x<<": "<<res<<endl;
    }
}

void a1(){
    int n, m, r;
    cin>>n>>m>>r;
    int minimo = 1000;
    int aux;
    REP(i,1,n){
        cin>>aux;
        if(aux<minimo) minimo = aux;
    }
    int maximo = -1;
    REP(i,1,m){
        cin>>aux;
        if(aux>maximo) maximo = aux;
    }
    if(maximo <= minimo){
        cout<<r<<'\n';
    }
    else{
        cout<<r/minimo*maximo + r%minimo<<'\n';
    }
}

void b1(){
    int n;
    cin>>n;
    vector<string> t(n);
    REP(i,0,n-1){
        cin>>t[i];
    }
    REP(i,0,n-1){
        REP(j,0,n-1){
            if(t[i][j] == '.'){
                if(j<n-1 && i<n-2 && j>0 && t[i+1][j+1] == '.' && t[i+1][j] == '.' && t[i+1][j-1] == '.' && t[i+2][j] == '.'){
                    t[i][j]='#';
                    t[i+1][j] = '#';
                    t[i+1][j-1] = '#';
                    t[i+1][j+1] = '#';
                    t[i+2][j] = '#';
                }
                else {
                    cout<<"NO"<<'\n';
                    return;
                }
            }
        }
    }
    cout<<"YES"<<'\n';
}

void c1(){
    int n;
    cin>>n;
    int aux;
    int unos = 0;
    int dos = 0;
    REP(i,1,n){
        cin>>aux;
        if(aux==1) unos++;
        else dos++;
    }
    if(dos == 0){
        while(unos--) cout<<"1 ";
        cout<<'\n';
        return;
    }
    if(unos == 0){
        while(dos--) cout<<"2 ";
        cout<<'\n';
        return;
    }
    cout<<"2 1 ";
    dos--;
    unos--;
    while(dos--){
        cout<<"2 ";
    }
    while(unos--){
        cout<<"1 ";
    }
    cout<<'\n';
}

int main(){
    c1();
    return 0;
}