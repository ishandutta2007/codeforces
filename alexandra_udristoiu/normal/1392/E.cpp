#include<iostream>
using namespace std;
int n, q, i, j, ii;
long long a[30][30], d[30][30], sum, d2[30][30];
long long val(int i, int j){
    if(i <= n && j <= n){
        return d2[i][j];
    }
    return (1LL << 60);
}
int main(){
    cin>> n;
    for(ii = n - 1; ii >= 1; ii--){
        i = n;
        j = ii;
        d[i][j] = max(d[i + 1][j], d[i][j + 1]);
        d2[i][j] = min(val(i + 1, j), val(i, j + 1) );
        while(i - 1 > 0 && j + 1 <= n){
            i--;
            j++;
            d2[i][j] = min( val(i + 1, j), val(i, j + 1) );
            a[i][j] = d[i + 1][j - 1] + 1 - d2[i][j];
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i][j + 1]);
            d2[i][j] += a[i][j];
        }
    }
    for(ii = n - 1; ii > 1; ii--){
        i = ii;
        j = 1;
        d[i][j] = max(d[i + 1][j], d[i][j + 1]);
        d2[i][j] = min(val(i + 1, j), val(i, j + 1) );
        while(i - 1 > 0 && j + 1 <= n){
            i--;
            j++;
            d2[i][j] = min( val(i + 1, j), val(i, j + 1) );
            a[i][j] = d[i + 1][j - 1] + 1 - d2[i][j];
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i][j + 1]);
            d2[i][j] += a[i][j];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
    cout.flush();
    cin>> q;
    for(; q; q--){
        cin>> sum;
        i = j = 1;
        cout<<"1 1\n";
        while(i < n || j < n){
            if(j == n || sum < d2[i][j + 1]){
                i++;
            }
            else{
                j++;
            }
            cout<< i <<" "<< j <<"\n";
            sum -= a[i][j];
        }
    }
}