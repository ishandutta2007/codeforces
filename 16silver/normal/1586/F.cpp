#include <bits/stdc++.h>
using namespace std;
int ans[1000][1000];
int n,k;
void f(int a, int b, int c){
    if(a>=n || b>=n) return;
    ans[a][b] = c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int cur = k, col = 1;
    while(true){
        for(int i=0;i<n;i+=cur){
            for(int j=0;j<k;j++){
                if(j*(cur/k)>=n) break;
                for(int l=j+1;l<k;l++){
                    if(l*(cur/k)>=n) break;
                    for(int p=0;p<cur/k;p++){
                        if(i+j*(cur/k)+p>=n) break;
                        for(int q=0;q<cur/k;q++){
                            if(i+l*(cur/k)+q>=n) break;
                            f(i+j*(cur/k)+p, i+l*(cur/k)+q, col);
                        }
                    }
                }
            }
        }
        if(cur>=n) break;
        cur *= k;
        col++;
    }
    cout << col << "\n";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) cout << ans[i][j] << " ";
        // cout << "\n";
    }
}