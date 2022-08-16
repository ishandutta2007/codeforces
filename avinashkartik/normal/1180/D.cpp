#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main(){
    int q,n,m,x;
    cin>>n>>m;

    for(int i = 1; i < (n+1)/2+1; i++){
        for(int j = 1; j <= m; j++){
            printf("%d %d\n",i,j);
            if(i == n+1-i and j > m/2)
                break;
            if(!(i == n+1-i and j == m/2 and m%2 == 0))
                printf("%d %d\n",n+1-i,m+1-j);
            
        }
    }
}