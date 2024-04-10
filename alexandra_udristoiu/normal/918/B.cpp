#include<iostream>
#include<cstring>
using namespace std;
int n, m, i, j;
char nm[1005][25], ip[1005][25], s[25], c[25];
int comp(char a[], char b[]){
    for(int i = 0; i < 20; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>> n >> m;
    for(i = 1; i <= n; i++){
        cin>> nm[i] >> ip[i];
        ip[i][ strlen(ip[i])] = ';';
    }
    for(i = 1; i <= m; i++){
        memset(s, 0, sizeof(s));
        cin>> c >> s;
        for(j = 1; j <= n; j++){
            if(comp(s, ip[j])){
                cout<< c <<" "<< s <<" #" << nm[j] <<"\n";
                break;
            }
        }
    }
}