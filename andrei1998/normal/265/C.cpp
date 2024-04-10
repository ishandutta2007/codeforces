#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque <int> ans;

int main()
{
    string str;
    cin >> str;

    for (int i = str.size() - 1; i >= 0; -- i) {
        if (str[i] == 'r')
            ans.push_front(i + 1);
        else
            ans.push_back(i + 1);
    }

    for (auto it: ans)
        cout << it << '\n';
    return 0;
}