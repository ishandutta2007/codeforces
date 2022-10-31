#include<iostream>
#include<algorithm>
#define f first
#define s second
using namespace std;
int n, i, j, pos, u;
int v[1005], a[1005][1005];
pair<int, int> p[1005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(i = 1; i <= n + 1; i++){
        p[i] = make_pair(1, i);
    }
    for(i = 1; i <= n; i++){
        pos = -1;
        for(j = 1; j <= n; j++){
            if(p[j].f == p[j + 1].f){
                pos = j;
                v[i]--;
                a[ p[j].s ][i] = 1;
                break;
            }
        }
        for(j = 1; j <= n + 1 && v[i] > 0; j++){
            if(j != pos && j != pos + 1){
                v[i]--;
                a[ p[j].s ][i] = 1;
            }
        }
        for(j = 1; j <= n + 1; j++){
            p[j].f = p[j].f * 2 + a[ p[j].s ][i];
        }
        sort(p + 1, p + n + 2);
        for(j = 1; j <= n + 1; j++){
            u = j + 1;
            while(u <= n + 1 && p[j].f == p[u].f){
                p[u].f = j;
                u++;
            }
            p[j].f = j;
            j = u - 1;
        }
    }
    cout<< n + 1 <<"\n";
    for(i = 1; i <= n + 1; i++){
        for(j = 1; j <= n; j++){
            cout<< a[i][j];
        }
        cout<<"\n";
    }
}