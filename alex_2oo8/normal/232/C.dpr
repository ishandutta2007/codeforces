program problem3;

var fib: array[0..78] of int64;
    arr: array[ 1..78, 1..4 ] of longWord;
    id: array[ 1..78, 0..1 ] of int64;

function min( a, b: longWord ): longWord;
begin
  if ( a < b ) then
    min := a
  else
    min := b;
end;

function minPath( a, b: int64; n: longWord ): longWord;
var res, k: longWord;
    i: longWord;
    minAB, maxAB: int64;
begin
  if ( a > b ) then
  begin
    maxAB := a;
    minAB := b;
  end
  else
  begin
    maxAB := b;
    minAB := a;
  end;

  if ( a = b ) then
  begin
    minPath := 0;
    exit;
  end
  else if ( n = 1 ) then
  begin
    minPath := 1;
    exit;
  end
  else if ( minAB = 1 ) and ( maxAB = fib[n] ) then
  begin
    minPath := ( n + 1 ) div 2;
    exit;
  end;

  if ( minAB = 1 ) and ( maxAB = id[n][0] ) then
    i := 1
  else if ( minAB = 1 ) and ( maxAB = id[n][1] ) then
    i := 2
  else if ( maxAB = fib[n] ) and ( minAB = id[n][0] ) then
    i := 3
  else if ( maxAB = fib[n] ) and ( minAB = id[n][1] ) then
    i := 4
  else
    i := 0;

  if ( i <> 0 ) and ( arr[n][i] <> 0 ) then
  begin
    minPath := arr[n][i];
    exit;
  end;

  if ( minAB = 1 ) then
  begin
    if ( maxAB > fib[n-1] ) then
      res := minPath( ( maxAB - fib[n-1] ), 1, (n-2) ) + 1
    else
    begin
      res := minPath( maxAB, 1,        (n-1) );
      k   := minPath( maxAB, fib[n-1], (n-1) ) + 2;

      res := min( res, k );
    end;
  end
  else if ( a <= fib[n-1] ) and ( b <= fib[n-1] ) then
  begin
    res := minPath( a, b, (n-1) );
    k := minPath( a, 1, (n-1) ) + minPath( b, fib[n-1], (n-1) ) + 2;
    res := min( res, k );
    k := minPath( b, 1, (n-1) ) + minPath( a, fib[n-1], (n-1) ) + 2;
    res := min( res, k );
  end
  else if ( maxAB = fib[n] ) then
  begin
    if ( minAB > fib[n-1] ) then
      res := minPath( ( minAB - fib[n-1] ), fib[n-2], (n-2) )
    else
    begin
      res := minPath( minAB, 1,        (n-1) );
      k   := minPath( minAB, fib[n-1], (n-1) );

      res := min( res, k ) + 1 + minPath( 1, fib[n-2], (n-2) );
    end;
  end
  else if ( a > fib[n-1] ) and ( b > fib[n-1] ) then
    res := minPath( ( a - fib[n-1] ), ( b - fib[n-1] ), (n-2) )
  else
  begin
    res := minPath( minAB, 1,        (n-1) );
    k   := minPath( minAB, fib[n-1], (n-1) );
    res := min( res, k );

    k := minPath( ( maxAB - fib[n-1] ), 1, (n-2) );
    res := res + k + 1;
  end;

  if ( i <> 0 ) then
    arr[n][i] := res;

  minPath := res;
end;

var t, n, i, j: longWord;
    a, b, ap, bp: int64;

begin
  fib[0] := 1;
  fib[1] := 2;
  for i := 2 to 78 do
    fib[i] := fib[i-1] + fib[i-2];

  readln( t, n );

  n := min( n, 78 );

  for i := 1 to t do
  begin
    fillchar( arr, sizeOf(arr), 0 );

    readln( a, b );

    ap := a;
    bp := b;
    for j := n downTo 1 do
    begin
      if ( ap > fib[j] ) then
        ap := ap - fib[j];
      if ( bp > fib[j] ) then
        bp := bp - fib[j];

      id[j][0] := ap;
      id[j][1] := bp;
    end;

    writeln( minPath( a, b, n ) );
  end;
end.