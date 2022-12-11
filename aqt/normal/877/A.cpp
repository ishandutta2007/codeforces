#include <bits/stdc++.h>

using namespace std;

string names[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string s;
int cnt[5];

int main(){
    cin >> s;
    for(int i = 0; i<150; i++){
        s += '?';
    }
    for(int i = 0; i<100; i++){
        for(int j= 0; j<5; j++){
            if(s.substr(i, names[j].size()) == names[j]){
                cnt[j]++;
            }
        }
    }
    sort(cnt, cnt+5);
    if(cnt[4] == 1 && cnt[3] == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO"  << endl;
    }
}