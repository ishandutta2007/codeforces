#include<iostream>
#include<vector>
#define DIM 200005
using namespace std;
int n, i, ii, p, ok, t;
char s[DIM], sol[DIM];
vector<int> v[12];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        for(i = 0; i < 10; i++){
            v[i].clear();
        }
        for(i = 1; i <= n; i++){
            sol[i] = 0;
            v[ s[i] - '0' ].push_back(i);
        }
        sol[n + 1] = 0;
        p = 0;
        for(ii = 0; ii < 10; ii++){
            if(v[ii].size() == 0){
                continue;
            }
            if(p < v[ii][0]){
                for(i = 0; i < v[ii].size(); i++){
                    sol[ v[ii][i] ] = '1';
                }
                p = v[ii][i - 1];
            }
            else{
                for(i = 0; i < v[ii].size(); i++){
                    if(v[ii][i] > p){
                        sol[ v[ii][i] ] = '1';
                    }
                }
                break;
            }
        }
        ok = 1;
        for(i = 1; i <= n; i++){
            if(sol[i] == 0){
                sol[i] = '2';
                if(s[i] < s[p]){
                    ok = 0;
                }
                p = i;
            }
        }
        if(ok == 0){
            cout<<"-\n";
        }
        else{
            cout<< sol + 1 <<"\n";
        }
    }
}