    #include<bits/stdc++.h>
    using namespace std;
    const int N = 1e6;
    int n, a[N], b[N], c[N], p[N], q[N], was[N];
    bool cmp(int i, int j){
    	return a[i] < a[j] ||(a[i] == a[j] && b[i] < b[j]) || (a[i] == a[j] && b[i] == b[j] && c[i] < c[j]);
    }
    void print(int i, int j){
    	was[i] = was[j] = 1;
    	printf("%d %d\n", i + 1, j + 1);
    }
    void rem(){
    	int k = 0;
    	for(int i = 0; i < n; i++)
    		if(!was[p[i]])
    			q[k++] = p[i];
    	n = k;
    	for(int i = 0; i < n; i++)
    		p[i] = q[i];
    }
    int main()
    {
    	scanf("%d", &n);
    	for(int i = 0; i < n; i++){
    		scanf("%d%d%d", &a[i], &b[i], &c[i]);
    		p[i] = i;
    	}
    	sort(p, p + n, cmp);
    	for(int i = 0, j = 0; i < n; i = j){
    		while(j < n && a[p[i]] == a[p[j]] && b[p[i]] == b[p[j]])
    			j++;
    		for(int q = 0; i + q  + 1 < j; q += 2)
    			print(p[i + q], p[i + q + 1]); 	
    	}	
    	rem();
    	for(int i = 0, j = 0; i < n; i = j){
    		while(j < n && a[p[i]] == a[p[j]])
    			j++;
    		for(int q = 0; i + q  + 1 < j; q += 2)
    			print(p[i + q], p[i + q + 1]); 	
    	}	
    	rem();
        for(int i = 0, j = 0; i < n; i = j){
    		while(j < n)
    			j++;
    		for(int q = 0; i + q  + 1 < j; q += 2)
    			print(p[i + q], p[i + q + 1]); 	
    	}	
        return 0;
    }