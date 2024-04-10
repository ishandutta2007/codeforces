	#include<cstdio>


	#include<cstring>


	#include<cmath>


	#include<cstdlib>

			#include<iostream>



		#include<algorithm>

		#include<string>



		#include<vector>


		#include<queue>

			#include<set>


			#include<map>

		using namespace std;



		typedef long long ll;


#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
			inline int read ( )


	{


	int a=0 ,  f=1; char c=getchar   (  )  ;


	while  (  c<'0'||c>'9'  )

		{ if (  c ==  '-'   )  f=-1; c=getchar ( ) ; }



		while   (  c   >= '0'&&c   <=   '9'   ) a=a*10+c-'0'   ,   c=getchar (  )   ;


			return a*f;

		   }

		int a   [ 100005   ]  ;

		map<ll   ,  int> h;


	int main  ( )


	{

		int n=read (  )   , k=read   (  )  ;


	rep (   i   ,   1 , n )  a   [  i ] =read  (   )  ;


	ll t=1  ,  ans=0;

		rep  ( i  , 1  ,  60  )


	{


	ll tt=0;

		h.clear (  )  ;


		h [   0 ]  ++ ;



	rep (  j  ,   1  , n )



	{

	tt  += a [   j  ]  ;


		ans   += h   [  tt-t   ]  ;

		h [ tt   ]  ++  ;



		 }


		t *= k;


	if (  t>1e14||t<-1e14||t  ==   1   )  break;


			  }



	printf  ( "%lld\n" ,  ans )   ;

	return 0;		


	 }