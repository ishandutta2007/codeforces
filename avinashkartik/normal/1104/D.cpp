    #include<bits/stdc++.h>
    using namespace std;
     
    bool tell(int a, int b)
    {
    	cout << "? " << a << ' ' << b << '\n';
    	char c;
    	cout.flush();
    	cin >> c;
    	return (c == 'x');
    }
     
    void test()
    {
    	string s;
    	cin >> s;
    	if (s != "start")
    		return;
    	int a = 1, b = 2;
    	while (!tell(a, b))
    		a *= 2, b *= 2;
     
    	for (int i = 29; i >= 0; i--)
    		if (b - (1 << i) > a && tell(a, b - (1 << i)))
    			b -= (1 << i);
     
    	if (b == 2 && a == 1 && tell(2, 1))
    		cout << "! 1\n";
    	else
    		cout << "! " << b << '\n';
    	cout.flush();
    	test();
    }
     
    int main()
    {
    	test();
    	return 0;
    }