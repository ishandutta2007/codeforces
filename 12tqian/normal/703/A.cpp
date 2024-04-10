#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a = 0;
    int b = 0;
    for(int i = 0; i<n; i++){
        int m, c;
        cin >> m>> c;
        if(m>c){
            a+= 1;
        }
        else if(m<c){
             b+=1;
        }
    }
    if(a>b){
        cout<<"Mishka";
    }
    else if(a<b){
        cout << "Chris";
    }
    else{
        cout<<"Friendship is magic!^^";
    }

    return 0;
}