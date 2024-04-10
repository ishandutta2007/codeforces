#include <bits/stdc++.h>

using namespace std;

int gg[] = {2,	3,	5,	7,	11,	13,	17,	19,	23,	29,	31,	37,	41,	43,	47,	53,	59,	61,	67,	71, 73,	79,	83,	89,	97};

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int GG = 0;
    for(int i = 0; GG < 20; i++)
    {
        GG++;
        cout << gg[i] << endl;
        string ans;
        cin >> ans;
        cnt += ans == "yes";
        if(gg[i] * gg[i] <= 100)
        {
            if(GG == 20)
                continue;
            GG++;
            cout << gg[i] * gg[i] << endl;
            string ans;
            cin >> ans;
            cnt += ans == "yes";
        }
    }
    if(cnt <= 1)
        cout << "prime" << endl;
    else
        cout << "composite" << endl;
	return 0;
}