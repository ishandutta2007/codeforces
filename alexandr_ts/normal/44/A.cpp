#include <iostream>
#include <cstring>

using namespace std;

struct leaf
{
    string s1;
    string s2;
};

leaf a[1000];

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int er = 0;
        cin >> a[i].s1 >> a[i].s2;
        for(int j = 0; j < i; j++)
            if(a[i].s1 == a[j].s1 && a[j].s2 == a[i].s2)
                er = 1;
        if(er == 0)
            ans++;
    }
    cout << ans;

    return 0;
}