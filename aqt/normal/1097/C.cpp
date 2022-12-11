#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int arr[1500000];

int main(){
    cin >> N;
    getline(cin, s);
    int ans = 0;
    for(int i = 0; i<N; i++){
        getline(cin, s);
        int pre = 0, suf = 0, cnt = 0;
        for(int j = 0; j<s.size(); j++){
            cnt += s[j] == '(' ? 1 : -1;
            pre = min(cnt, pre);
        }
        cnt = 0;
        for(int j = s.size()-1; j>=0; j--){
            cnt += s[j] == ')' ? 1 : -1;
            suf = min(cnt, suf);
        }
        if(pre < 0 && suf < 0){
            continue;
        }
        else if(pre < 0){
            cnt = -pre;
        }
        else if(suf < 0){
            cnt = suf;
        }
        if(arr[750000-cnt]){
            ans++;
            arr[750000-cnt]--;
        }
        else{
            arr[750000+cnt]++;
        }
    }
    cout << ans << endl;
}