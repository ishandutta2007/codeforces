#include<iostream>
using namespace std;
int t, n, m, k, sum, nr, ind, r, curr, i, j;
char a[105][105];
char c[105][105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> m >> k;
        sum = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                cin>> a[i][j];
                if(a[i][j] == 'R'){
                    sum++;
                }
            }
        }
        ind = 0;
        nr = sum / k;
        r = sum % k;
        curr = 0;
        for(i = 1; i <= n; i++){
            if(i % 2 == 1){
                for(j = 1; j <= m; j++){
                    c[i][j] = ind;
                    if(a[i][j] == 'R'){
                        curr++;
                        if(ind < r && curr == nr + 1){
                            ind++;
                            curr = 0;
                        }
                        else{
                            if(ind >= r && curr == nr && ind != k - 1){
                                ind++;
                                curr = 0;
                            }
                        }
                    }
                }
            }
            else{
                for(j = m; j >= 1; j--){
                    c[i][j] = ind;
                    if(a[i][j] == 'R'){
                        curr++;
                        if(ind < r && curr == nr + 1){
                            ind++;
                            curr = 0;
                        }
                        else{
                            if(ind >= r && curr == nr && ind != k - 1){
                                ind++;
                                curr = 0;
                            }
                        }
                    }
                }
            }
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= m; j++){
                if(c[i][j] < 10){
                    cout<< (char) (c[i][j] + '0');
                }
                else{
                    if(c[i][j] < 36){
                        cout<< (char) (c[i][j] - 10 + 'a');
                    }
                    else{
                        cout<< (char) (c[i][j] - 36 + 'A');
                    }
                }
            }
            cout<<"\n";
        }
    }
}