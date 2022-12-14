#include<bits/stdc++.h>

using namespace std;

int a[101000];

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    string a;
    cin >> a;
    for (int i = 0; i < 8; i++){
        bool mark = true;
        string b = s[i];
        b += "123";
        if (s[i].size() != a.size())
            continue;
        for (int j = 0; j < a.size(); j++){
            if (a[j] != '.' && a[j] != b[j])
                mark = false;
        }
        if (mark == true){
            cout << s[i] << endl;
            return 0;
        }
    }
}