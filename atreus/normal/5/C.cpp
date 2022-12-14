#include <iostream>
#include <stack>
#include <map>

using namespace std;

const int maxn = 1e6 + 600;
int l[maxn];
stack <int> st;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (!st.empty() && s[i] == ')'){
            l[i] = i - st.top() + 1;
            if (st.top() != 0)
                l[i] += l[st.top() - 1];
            st.pop();
        }
        if (s[i] == '(')
            st.push(i);
    }
    int k = 0, cnt = 0;
    for (int i = 0; i < s.size(); i++)
        k = max(k, l[i]);
    for (int i = 0; i < s.size(); i++)
        if (l[i] == k)
            cnt ++;
    if (k == 0)
        cnt = 1;
    cout << k << " " << cnt << endl;
}