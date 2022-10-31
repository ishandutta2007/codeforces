#include<iostream>
using namespace std;
int t, n, k, i, j, nr, ii, jj;
char s[2005], sol[2005];
pair<int, int> p[2005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        cin>> s + 1;
        k--;
        for(i = 1; i <= 2 * k; i += 2){
            sol[i] = '(';
            sol[i + 1] = ')';
        }
        nr = (n - i + 1) / 2;
        for(; i <= n; i++){
            if(nr > 0){
                sol[i] = '(';
                nr--;
            }
            else{
                sol[i] = ')';
            }
        }
        nr = 0;
        for(i = 1; i <= n; i++){
            if(s[i] != sol[i]){
                for(j = i + 1; j <= n; j++){
                    if(s[j] == sol[i]){
                        break;
                    }
                }
                p[++nr] = make_pair(i, j);
                for(ii = i, jj = j; ii < jj; ii++, jj--){
                    swap(s[ii], s[jj]);
                }
            }
        }
        cout<< nr <<"\n";
        for(i = 1; i <= nr; i++){
            cout<< p[i].first <<" "<< p[i].second <<"\n";
        }
    }
}