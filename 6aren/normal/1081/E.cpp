#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int N=2e5+5;

int n, x[N], a[N];
vector <ii> p[N];

int main(){
    cin >> n;
    int maxi=0;
    for (int i=2; i<=n; i+=2){
        cin >> x[i];
        maxi=max(maxi, x[i]);
    }
    for (int i=1; i<=maxi; i++){
        for (int j=i+1; (1LL*j*j-1LL*i*i)<=maxi; j++){
            p[1LL*j*j-1LL*i*i].push_back(make_pair(i, j));
        }
    }
    a[0]=0;
    for (int i=2; i<=n; i+=2){
        int check=0;
        for (int j=0; j<p[x[i]].size(); j++){
            int u=p[x[i]][j].first;
            int v=p[x[i]][j].second;
            if (u>a[i-2]){
                a[i-1]=u;
                a[i]=v;
                check=1;
                break;
            }
        }
        if (!check) return cout << "No \n", 0;
    }
    cout << "Yes \n";
    for (int i=1; i<=n; i++){
        cout << 1LL*a[i]*a[i]-1LL*a[i-1]*a[i-1] << " ";
    }
}