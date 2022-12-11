#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 1;
    int s1 = 0, s2 = 0;
    while(N--){
        int c1,c2;
        cin >> c1 >> c2;
        while(s1 != c1 && s2 != c2){
            if(s1 < s2){
                s1++;
            }
            else{
                s2++;
            }
            if(s1 == s2){
                cnt++;
            }
        }
        while(s1 != c1){
            s1++;
            if(s1 == s2){
                cnt++;
            }
        }
        while(s2 != c2){
            s2++;
            if(s1 == s2){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}