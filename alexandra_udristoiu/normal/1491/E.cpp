#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, x, y, nr, nod2, niv1, niv2;
int viz[DIM], t[DIM], fib[50], num[DIM];
vector<int> v[DIM];
void dfs(int nod, int tt, int k, int n){
    num[nod] = 1;
    viz[nod] = nr + 1;
    t[nod] = tt;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == k && vecin != tt){
            dfs(vecin, nod, k, n);
            num[nod] += num[vecin];
        }
    }
    if(num[nod] == fib[n - 1] || num[nod] == fib[n - 2]){
        nod2 = nod;
        niv1 = n - 1;
        niv2 = n - 2;
        if(num[nod] == fib[n - 1]){
            swap(niv1, niv2);
        }
    }
}
void dfs2(int nod, int t, int k){
    viz[nod] = nr + 2;
    for(int i = 0; i < v[nod].size(); i++){
        int vecin = v[nod][i];
        if(viz[vecin] == nr + 1 && vecin != t){
            dfs2(vecin, nod, k);
        }
    }
}
int solve(int k, int nod, int n){
    if(n <= 1){
        return 1;
    }
    nod2 = 0;
    dfs(nod, 0, k, n);
    if(nod2 == 0){
        return 0;
    }
    dfs2(nod2, t[nod2], k);
    nr += 2;
    int x = nr - 1, y = nr;
    int nod22 = nod2, niv22 = niv2;
    int ok1 = solve(x, nod, niv1);
    int ok2 =  solve(y, nod22, niv22);
    if(ok1 == 1 && ok2 == 1){
        return 1;
    }
    return 0;
}
int main(){
    cin>> n;
    for(i = 1; i < n; i++){
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n == 1){
        cout<<"YES";
        return 0;
    }
    fib[0] = fib[1] = 1;
    for(i = 2; i < 50; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        if(n == fib[i]){
            break;
        }
        if(n < fib[i]){
            cout<<"NO";
            return 0;
        }
    }
    nr = 1;
    int ok = solve(0, 1, i);
    if(ok == 1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}