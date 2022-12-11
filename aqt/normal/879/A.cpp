#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    int lst = 0;
    for(int i = 1; i<=N; i++){
        int m, b;
        cin >> b >> m;
        if(lst+1 < b){
            lst = b;
        }
        else{
            lst++;
            while((lst-b)%m){
                lst++;
            }
        }
    }
    cout << lst << endl;
}