#include<iostream>
#include<algorithm>
#define f first
#define s second
using namespace std;
int n, i, j, ii, nod, u, nr, x, num, val, nrs;
int w[505];
pair<int, int> v[505], sol[505], c[505];
int cmp(pair<int, int> a, pair<int, int> b){
    return a.s < b.s;
}
int main(){
    cin>> n;
    v[1] = make_pair(1, n);
    for(i = 2; i <= n; i++){
        cout<<"1\n1\n"<< n - 1 <<"\n";
        for(j = 2; j <= n; j++){
            cout<< j <<" ";
        }
        cout<<"\n"<< i <<"\n";
        cout.flush();
        cin>> x;
        v[i] = make_pair(i, x);
    }
    sort(v + 1, v + n + 1, cmp);
    for(i = 1; i <= n; i++){
        num = v[i].s;
        while(num != 1){
            val = 0;
            for(ii = 0; (1 << ii) <= n; ii++){
                nr = 0;
                for(j = 1; j <= u; j++){
                    if( (c[j].f & ( (1 << (ii + 1) ) - 1 ) ) == val){
                        w[++nr] = c[j].f;
                    }
                }
                if(nr == 0){
                    val += (1 << ii);
                }
                else{
                    cout<<"1\n1\n"<< nr <<"\n";
                    for(j = 1; j <= nr; j++){
                        cout<< w[j] <<" ";
                    }
                    cout<<"\n"<< v[i].f <<"\n";
                    cout.flush();
                    cin>> x;
                    if(x == 0){
                        val += (1 << ii);
                    }
                }
            }
            sol[++nrs] = make_pair(v[i].f, val);
            for(j = 1; j <= u; j++){
                if(c[j].f == val){
                    num -= c[j].s;
                    swap(c[j], c[u]);
                    u--;
                    break;
                }
            }
        }
        c[++u] = v[i];
    }
    cout<<"ANSWER\n";
    for(i = 1; i < n; i++){
        cout<< sol[i].f <<" "<< sol[i].s <<"\n";
    }
    cout.flush();
}