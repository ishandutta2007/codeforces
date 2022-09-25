program problem5;
uses math;

type	tArr =	array[ 1..100000 ] of longInt;
		tSet =	record
					cnt: longInt;
					f: tArr;
				end;

var	n: longInt;

procedure qsort( var a: tArr; l, r: longInt );
var	i, j, t, med: longInt;
begin
	if ( l < r ) then
	begin
		i := l;
		j := r;
		med := a[ l + random(r - l + 1) ];
		while ( i <= j ) do
		begin
			while ( a[i] < med ) do
				inc( i );
			while ( a[j] > med ) do
				dec( j );
			
			if ( i <= j ) then
			begin
				t := a[i];
				a[i] := a[j];
				a[j] := t;
			
				inc( i );
				dec( j );
			end;
		end;
		
		qsort( a, l, j );
		qsort( a, i, r );
	end;
end;

function C( n, k: longInt ): int64;
var	res: int64;
	i: longInt;
begin
	res := 1;
	for i := 1 to k do
		res := ( res * (n - i + 1) ) div i;
	
	exit( res );
end;

procedure updateAns( var ans, val: int64; newAns, newVal: int64 );
begin
	if ( newVal > val ) then
	begin
		ans := newAns;
		val := newVal;
	end
	else if ( newVal = val ) then
		ans := ans + newAns;
end;

procedure addToSet( var s: tSet; x: longInt );
begin
	with s do
	begin
		inc( cnt );
		f[cnt] := x;
	end;
end;

procedure initSet( var s: tSet );
begin
	qsort( s.f, 1, s.cnt );
end;

procedure calcInsideSet( var s: tSet; var ans, val: int64 );
var	cntMin, cntMax, cntMid: longInt;
begin
	with s do
	begin
		if ( cnt < 3 ) then
		begin
			ans := 0;
			val := -2;
			
			exit();
		end;
		
		val := 2 * int64( f[cnt] - f[1] );
		
		if ( f[cnt] = f[1] ) then
		begin
			ans := C(cnt, 3);
			exit();
		end;
		
		cntMin := 1;
		while ( f[cntMin + 1] = f[1] ) do
			inc( cntMin );
		
		cntMax := 1;
		while ( f[cnt - cntMax] = f[cnt] ) do
			inc( cntMax );
			
		cntMid := cnt - cntMin - cntMax;
		
		ans := cntMin * int64(cntMid) * cntMax + C(cntMin, 2) * cntMax + cntMin * C(cntMax, 2);
	end;
end;

procedure calcForTwoSets( var s1, s2: tSet; var ans, val: int64 );

	procedure case1( var ans, val: int64 );
	var	i, j, cntL: longInt;
	begin
		val := -3;
		
		j := 0;
		for i := 1 to s1.cnt - 1 do
		begin
			while ( j < s2.cnt ) and ( s2.f[j + 1] <= s1.f[i] ) do
				inc( j );
			
			if ( j > 0 ) then
				val := max( val, 2 * int64( n + s2.f[j] - s1.f[i] ) );
		end;
		
		ans := 0;
		j := 0;
		cntL := 0;
		for i := 1 to s1.cnt - 1 do
		begin
			while ( j < s2.cnt ) and ( s2.f[j + 1] <= s1.f[i] ) do
			begin
				if ( j > 0 ) and ( s2.f[j + 1] = s2.f[j] ) then
					inc( cntL )
				else
					cntL := 1;
				
				inc( j );
			end;
			
			if ( j > 0 ) and ( 2 * int64( n + s2.f[j] - s1.f[i] ) = val ) then
				ans := ans + cntL * int64( s1.cnt - i );
		end;
	end;
	
	procedure case2( var ans, val: int64 );
	var	i, j, k: longInt;
	begin
		val := 2 * int64(n);
		ans := 0;
		
		j := 0;
		k := 1;
		for i := 1 to s2.cnt do
		begin
			while ( j < s1.cnt ) and ( s1.f[j + 1] < s2.f[i] ) do
				inc( j );
			
			while ( k <= s1.cnt ) and ( s1.f[k] < s2.f[i] ) do
				inc( k );
			
			ans := ans + j * int64( s1.cnt - k + 1 );
		end;
		
		if ( ans = 0 ) then
			val := -100;
	end;
	
	procedure case3( var ans, val: int64 );
	var	i, j, cntRight: longInt;
	begin
		val := -3;
		
		j := s2.cnt + 1;
		for i := s1.cnt downto 2 do
		begin
			while ( j > 1 ) and ( s2.f[j - 1] > s1.f[i] ) do
				dec( j );
			
			if ( j <= s2.cnt ) then
				val := max( val, 2 * int64( n + s1.f[i] - s2.f[j] ) );
		end;
		
		ans := 0;
		j := s2.cnt + 1;
		cntRight := 0;
		for i := s1.cnt downto 2 do
		begin
			while ( j > 1 ) and ( s2.f[j - 1] > s1.f[i] ) do
			begin
				if ( j <= s2.cnt ) and ( s2.f[j - 1] = s2.f[j] ) then
					inc( cntRight )
				else
					cntRight := 1;
			
				dec( j );
			end;
			
			if ( j <= s2.cnt ) and ( 2 * int64( n + s1.f[i] - s2.f[j] ) = val ) then
				ans := ans + cntRight * int64( i - 1 );
		end;
	end;

var	newAns, newVal: int64;
begin
	ans := 0;
	val := -2;
	
	case1( newAns, newVal );
	updateAns( ans, val, newAns, newVal );
	
	case2( newAns, newVal );
	updateAns( ans, val, newAns, newVal );
	
	case3( newAns, newVal );
	updateAns( ans, val, newAns, newVal );
end;

var	m, i, s, f: longInt;
	zero, one: tSet;
	ans, newAns, val, newVal: int64;

begin
	readln( n, m );
	for i := 1 to m do
	begin
		readln( s, f );
		
		if ( s = 0 ) then
			addToSet( zero, f )
		else
			addToSet( one, f );
	end;
	
	initSet( zero );
	initSet( one );
	
	ans := 0;
	val := -1;
	
	calcInsideSet( zero, newAns, newVal );
	updateAns( ans, val, newAns, newVal );
	
	calcInsideSet( one, newAns, newVal );
	updateAns( ans, val, newAns, newVal );

	calcForTwoSets( zero, one, newAns, newVal );
	updateAns( ans, val, newAns, newVal );

	calcForTwoSets( one, zero, newAns, newVal );
	updateAns( ans, val, newAns, newVal );
	
	writeln( ans );
end.