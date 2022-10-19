#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    double n , x , y;
    cin >> n >> x >> y;
    set<double> st;

    for(int i = 0 ;i < n ; i++)
    {
        double x1 , y1;
        cin >> x1 >> y1;

        x1 -= x ; y1 -= y;
        if(y1 == 0)
        {
            st.insert(1e5);
        }
        else
        {
            st.insert(x1 / y1);
        }
    }
    cout << st.size() << endl;

    return 0;
}