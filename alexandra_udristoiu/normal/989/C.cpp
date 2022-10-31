#include<iostream>
using namespace std;
int i, j, ii, jj, x;
int v[200], st[200], dr[200];
char a[55][55];
int main(){
    for(i = 1; i <= 4; i++){
        cin>> v[i];
        v[i]--;
    }
    for(ii = 'A'; ii <= 'D'; ii++){
        st[ii] = 1 + dr[ii - 1];
        dr[ii] = st[ii] + 9;
        for(i = st[ii]; i <= dr[ii]; i++){
            for(j = 1; j <= 50; j++){
                a[i][j] = ii;
            }
        }
    }
    for(ii = 1; ii <= 4; ii++){
        x = ii + 'A' - 1;
        jj = x + 1;
        if(jj == 'E'){
            jj = 'A';
        }
        for(i = st[jj] + 1; i < dr[jj]; i += 2){
            for(j = 1; j <= 50; j++){
                if( (i + j) % 2 == 1 && v[ii] > 0){
                    v[ii]--;
                    a[i][j] = x;
                }
            }
        }
    }
    cout<<"40 50\n";
    for(i = 1; i <= 40; i++){
        for(j = 1; j <= 50; j++){
            cout<< a[i][j];
        }
        cout<<"\n";
    }
}