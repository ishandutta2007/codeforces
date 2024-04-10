#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> st;
    string s;
    getline(cin, s);
    int N = s.size();
    for(int i = 1; i<N-1; i+=3){
        st.insert(s[i]);
    }
    cout << st.size() << endl;
}