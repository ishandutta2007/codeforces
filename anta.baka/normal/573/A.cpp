#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    bool ans = 1;
    int c = 0;
    for(int i=0, num; i<n; i++)
    {
        cin >> num;
        while(!(num%2)) num /= 2;
        while(!(num%3)) num /= 3;
        if(!c) c = num;
        if(num != c) ans = 0;
    }
    cout << (ans ? "Yes" : "No");
    return 0;
}