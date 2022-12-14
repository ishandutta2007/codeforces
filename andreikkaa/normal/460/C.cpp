#include <iostream>
#include <memory.h>

using namespace std;

int a[(int) 1e+5], a_[(int) 1e+5], t[(int) 1e+5 + 1];
int n, m, w;

int get(int r)
{
	int result = 0;
	for (; r > 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void update(int i, int x)
{
	for (; i <= n; i = (i | (i+1)))
		t[i] += x;
}

bool check(int h)
{
    int m_ = m;
    //cout << "m_ " << m_ << endl;
    //cout << "h " << h << endl;
    //cout << h << "!" << endl;
    /*for(int i = 0; i < n; ++i)
        cout << a_[i] << " ";
    cout << endl;*/
    for(int i = 0; i < n; ++i)
    {
        //cout << i + 1 << " " << i - w + 1<< " ; " << get(i + 1) << " - " << get(i - w + 1) << endl;
        a_[i] += get(i + 1) - get(i - w + 1);
        int d = h - a_[i];
        //cout << "a_ " << a_[i] << endl;
        //cout << d << " d" << endl;
        if(d <= 0)
            continue;
        m_ -= d;
        //cout << "new m_ " << m_ << endl;
        if(m_ < 0)
            return false;
        update(i + 1, d);
        /*for(int j = i; j - i < w and j < n; ++j)
        {
            a_[j] += d;
            //cout << i << " & " << a_[i] << endl;
        }*/
    }
    return true;
}

int main()
{
    cin >> n >> m >> w;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = 1e+9 + 1e+5, c;
    while(r - l > 1)
    {
        memcpy(a_, a, n * sizeof(int));
        memset(t, 0, (n + 1) * sizeof(int));
        c = (l + r) / 2;
        if(check(c))
            l = c;
        else
            r = c;
    }
    //cout << l << "-" << r << endl;
    memcpy(a_, a, n * sizeof(int));
    memset(t, 0, (n + 1) * sizeof(int));
    if(check(r))
        cout << r;
    else
        cout << l;
}