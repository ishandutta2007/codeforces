#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	long long a[n];
	vector <int> ch, nch;
	vector <vector <int> > och, onch;
	onch.resize(k - p);
	och.resize(p);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] % 2)
			nch.push_back(i);
		else
			ch.push_back(i);
	}
	if(nch.size() < k - p)
	{
		cout << "NO";
		return 0;
	}

	for(int i = 0; i < k - p; i++)
	{
		onch[i].push_back(nch[nch.size() - 1]);
		nch.pop_back();
	}

	if(nch.size() % 2)
	{
		cout << "NO";
		return 0;
	}

	/*for(int i = 0; i < nch.size(); i++)
        cout << " L" << nch[i];*/

	if(nch.size() / 2 + ch.size() < p)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;

	int i;
	for(i = 0; i < p; i++)
	{
		if(ch.size() == 0)
			break;

		och[i].push_back(ch[ch.size() - 1]);
		ch.pop_back();
	}
	if(i != p)
	{
		for(; i < p; i++)
		{
			och[i].push_back(nch[nch.size() - 1]);
			och[i].push_back(nch[nch.size() - 2]);
			nch.pop_back();
			nch.pop_back();
		}
	}
	while(ch.size())
	{
        if(p != 0)
            och[och.size() - 1].push_back(ch[ch.size() - 1]);
        else
            onch[onch.size() - 1].push_back(ch[ch.size() - 1]);
		ch.pop_back();
	}
	while(nch.size())
	{
        if(p != 0)
            och[och.size() - 1].push_back(nch[nch.size() - 1]);
        else
            onch[onch.size() - 1].push_back(nch[nch.size() - 1]);
		nch.pop_back();
	}
	for(int j = 0; j < onch.size(); j++)
	{
		cout << onch[j].size() << " ";
		for(int l = 0; l < onch[j].size(); l++)
		{
			cout << a[onch[j][l]] << " ";
		}
		cout << endl;
	}
	for(int j = 0; j < och.size(); j++)
	{
		cout << och[j].size() << " ";
		for(int l = 0; l < och[j].size(); l++)
		{
			cout << a[och[j][l]] << " ";
		}
		cout << endl;
	}
	return 0;
}