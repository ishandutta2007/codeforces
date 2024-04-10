#include <bits/extc++.h>

using namespace std;

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, start, x;
    cin >> n >> start >> x;
    srand(time(0) + 1442 + (n ^ start) + x / n + start / n 
                  + 1LL * start * n % 14228 + (x ^ n ^ start));
    int magic = 1000 + rand() % 400;
    vector<tuple<int, int>> que;
    
    cout << "? " << start << endl;
    int val, nxt;
    cin >> val >> nxt;
    que.emplace_back(val, nxt);
    
    int p[n];
    iota(p, p + n, 1);
    swap(p[start - 1], p[n - 1]);
    random_shuffle(p, p + n - 1);
    for(int i = 0; i < min(magic, n - 1); i++)
    {
		cout << "? " << p[i] << endl;
		cin >> val >> nxt;
		que.emplace_back(val, nxt);
	}
	sort(begin(que), end(que));
	int kk = 0;
	while(kk + 1 < que.size() && get<0>(que[kk + 1]) < x)
		kk++;
	int cval = get<0>(que[kk]);
	int cnxt = get<1>(que[kk]);
	while(cval < x && cnxt != -1)
	{
		cout << "? " << cnxt << endl;
		cin >> cval >> cnxt;
	}
	cout << "! " << (cval >= x ? cval : -1) << endl;
    return 0;
}