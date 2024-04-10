#include <bits/stdc++.h>

using namespace std;

int query(string s){
    cout << s << endl;
    int ret;
    cin >> ret;
    if(!ret){
        exit(0);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    int len = 0;
    len = query("a");
    if(len == 300){
        for(int i = 1; i<=len; i++){
            t.push_back('b');
        }
        query(t);
    }
    len++;
    for(int i = 1; i<=len; i++){
        s.push_back('a');
    }
    int crnt = query(s);
    if(crnt == len){
        for(int i = 1; i<len; i++){
            t.push_back('b');
        }
        query(t);
    }
    for(int i = 1; i<=len; i++){
        s[i-1] = 'b';
        int temp = query(s);
        if(temp < crnt){
            crnt = temp;
        }
        else{
            s[i-1] = 'a';
        }
    }
    query(s);
}