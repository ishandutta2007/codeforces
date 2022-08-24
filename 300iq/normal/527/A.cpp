    #include <iostream>
    #include <algorithm>
    #define ll long long
    using namespace std;
    int main()
    {
        ll a, b, ans = 0;
        cin >> a >> b;
        ll tmp = a % b;
        if(tmp == 0)
        {
            cout << a / b << endl;
            return 0;
        }
        else
        {
            ans += a / b;
            a = max(tmp, b);
            b = tmp + b - a;
        }
        while(a % b)
        {
            tmp = a - b;
            a = max(b, tmp);
            b = b + tmp - a;
            ans++;
        }
        cout << ans + (a / b)<< endl;
    }