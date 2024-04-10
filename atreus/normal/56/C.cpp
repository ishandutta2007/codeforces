#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <stack>

using namespace std;

stack <string> st;
map <string, int> mp;
string s;

string name(int l){
    string k;
    for (int i = l; i < s.size(); i++){
        if (s[i] != '.' && s[i] != ',' && s[i] != ':')
            k += s[i];
        else
            break;
    }
    return k;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '.'){
            mp[st.top()] --;
            st.pop();
        }
        else if (s[i] == ','){
            mp[st.top()] --;
            st.pop();
            continue;
        }
        else {
            st.push(name(i));
            ans += mp[st.top()];
            mp[st.top()] ++;
            string a = name(i);
            i += name(i).size();
        }
    }
    cout << ans << endl;
}