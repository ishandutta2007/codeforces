#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set < set <char> > ans;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        set <char> a;
        for (int j = 0; j < str.size(); j++) a.insert(str[j]);
        ans.insert(a);
    }
    cout << ans.size();
    return 0;
}