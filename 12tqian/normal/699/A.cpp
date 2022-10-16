#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> d;
    vector<int> x;
    int n;
    scanf("%d", &n);
    string s;
    cin>>s;
    for(int i = 0; i<n; i++){
        if(s[i] == 'R'){
            d.emplace_back(1);
        }
        else{
            d.emplace_back(0);
        }
    }
    int prev;
    int best = -1;
    for(int i = 0; i<n; i++){
        int r;
        scanf("%d", &r);
        if(i == 0){
            prev = r;
            continue;
        }
        if(d[i] == 0 && d[i-1] == 1){
            int t = (r-prev)/2;
            if(best == -1 || t<best){
                best = t;
            }
        }
        prev = r;
    }
    cout << best << endl;
    return 0;

}