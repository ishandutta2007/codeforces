"use strict";[]
/*** Custom Header For JAVASCRIPT ***/
var min = Math.min
var max = Math.max

//_f should be primitive
var nDArray = function(_a, _f)
{
	if(!Array.isArray(_a)) return null;
	if(_a.length==1)
	{
		var _ret = [];
		while(_ret.push(_f)<_a[0]);
		return _ret
	}
	var _ret = [];
	while(_ret.push(nDArray(_a.slice(1),_f))<_a[0]);
	return _ret;
}


var INF = 1e9+9;
/*** End of Custom Header ***/
var main = function()
{
	var N = +readline()
	var A = ("0 "+readline()).split(" ").map(Number)
	var dp = nDArray([N+1,3],0)
	dp[0][0] = 0;
	dp[0][1] = INF;
	dp[0][2] = INF;
	for(var i=1; i<=N; i++)
	{
		dp[i][0] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]) );
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		if(A[i]==2 || A[i]==0) dp[i][2]=INF;
		if(A[i]==1 || A[i]==0) dp[i][1]=INF;
	}
	var ans = min(dp[N][0], min(dp[N][1],dp[N][2]));
	write(ans)
}


main()