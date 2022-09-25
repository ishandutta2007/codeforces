program problem4;

var str: ansistring;
    n: longWord;
    p: array[0..5000000] of longWord;
    arr: array[1..5000000] of longWord;

procedure calc( t: longWord );
var i, j, k, l, r: longInt;
begin
  l := 0;
  r := 0;
  for i := 1 to n do
  begin
    if ( r > i ) then
    begin
      j := l + r - i - t;

      if ( ( j - ( ( arr[j] - t ) div 2 ) ) > l ) then
        arr[i] := arr[j]
      else
      begin
        j := i - ( r - i ) + t;
        k := r;
        while ( j > 0 ) and ( k <= n ) and ( str[j] = str[k] ) do
        begin
          dec( j );
          inc( k );
        end;

        l := j + 1;
        r := k - 1;

        arr[i] := r - l + 1;
      end;
    end
    else
    begin
      j := i;
      k := i + t;
      while ( j > 0 ) and ( k <= n ) and ( str[j] = str[k] ) do
      begin
        dec( j );
        inc( k );
      end;

      l := j + 1;
      r := k - 1;

      arr[i] := r - l + 1;
    end;

    if ( arr[i] = (2*i-1+t) ) then
      p[2*i-1+t] := 1
    else
      p[2*i-1+t] := 0;
  end;
end;

var i: longWord;
    ans: qWord;

begin
  readln( str );
  n := length( str );

  calc( 0 );
  calc( 1 );

  ans := 0;
  for i := 1 to n do
  begin
    if ( p[i] = 1 ) then
      p[i] := p[ i div 2 ] + 1;

    ans := ans + p[i];
  end;

  writeln( ans );
end.