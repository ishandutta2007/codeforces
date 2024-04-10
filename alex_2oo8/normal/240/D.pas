program problem4;

type tArr = array[1..200000] of longWord;
     tAnsArr = array[1..600000] of longWord;

var a1: tArr;
    n, m: longWord;

procedure proc( var a0: tArr; var ansArr: tAnsArr; var ans: longWord; b: boolean );
var i, j, k: longWord;
begin
  k := 1;
  i := 1;
  j := n + 1;
  while ( k <= (n+m) ) do
  begin
    if ( b ) then
    begin
      if ( i <= n ) then
      begin
        a0[k] := i;
        inc( k );
        inc( i );
        while ( i <= n ) and ( a1[i-1] = a1[i] ) do
        begin
          a0[k] := i;
          inc( k );
          inc( i );
        end;
      end;
    end
    else
      b := true;

    if ( j <= (n+m) ) then
    begin
      a0[k] := j;
      inc( k );
      inc( j );
      while ( j <= (n+m) ) and ( a1[j-1] = a1[j] ) do
      begin
        a0[k] := j;
        inc( k );
        inc( j );
      end;
    end;
  end;

  ans := 0;
  i := 1;
  while ( i <= (n+m) ) do
  begin
    while ( i < (n+m) ) and ( a1[ a0[i+1] ] = a1[ a0[i] ] ) do
      inc( i );

    if not ( ( i = (n+m) ) and ( a1[ a0[i] ] = 0 ) ) then
    begin
      inc( ans );
      ansArr[ans] := i;
    end;
    inc( i );
  end;
end;

var i, j, k, ans0, ans2, ans: longWord;
    a0, a2, a: tArr;
    ansArr0, ansArr2, ansArr: tAnsArr;
    f: text;
    c: byte;

begin
  assign( f, 'input.txt' );
  reset( f );

  readln( f, n );
  for i := 1 to n do
    read( f, a1[i] );
  readln( f );
  readln( f, m );
  for i := 1 to m do
    read( f, a1[i+n] );

  close( f );

  proc( a0, ansArr0, ans0, true );
  proc( a2, ansArr2, ans2, false );

  if ( ans0 < ans2 ) then
  begin
    ans := ans0;
    ansArr := ansArr0;
    a := a0;
  end
  else
  begin
    ans := ans2;
    ansArr := ansArr2;
    a := a2;
  end;

  assign( f, 'output.txt' );
  rewrite( f );

  write( f, a[1] );
  for i := 2 to (n+m) do
    write( f, ' ', a[i] );
  writeln( f );

  writeln( f, ans );
  for i := 1 to ans do
    write( f, ansArr[i], ' ' );
  writeln( f );

  close( f );
end.