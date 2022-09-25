program problem3;

var str: ansistring;
    n, i, j, k, ans, left, ansl, ansr: longInt;
    s: array[1..100000] of char;
    p, l: array[0..100000] of longInt;
    b: boolean;

begin
  readln( str );
  n := length( str );

  j := 0;
  ans := -1;
  k := 0;
  p[0] := 0;
  left := 1;

  for i := 1 to n do
  begin
    if ( str[i] = '(' ) or ( str[i] = '[' ) then
    begin
      inc( j );
      s[j] := str[i];
      l[j] := i;
      p[j-1] := k;
      k := 0;
      b := false;
    end
    else if ( j = 0 ) then
    begin
      k := 0;
      left := i + 1;
      l[0] := i;
      b := false;
    end
    else
    begin
      if ( ( str[i] = ')' ) and ( s[j] = '(' ) ) or ( ( str[i] = ']' ) and ( s[j] = '[' ) ) then
      begin
        dec( j );
        left := l[j] + 1;
        k := k + p[j];
        p[j] := 0;

        if ( str[i] = ']' ) then
          inc( k );

        b := true;
      end
      else
      begin
        k := 0;
        j := 0;
        left := i + 1;
        l[0] := i;

        b := false;
      end;
    end;

    if ( b ) and ( k > ans ) then
    begin
      ans := k;
      ansl := left;
      ansr := i;
    end;
  end;

  if ( ans = -1 ) then
    writeln( '0' )
  else
  begin
    writeln( ans );
    writeln( copy( str, ansl, (ansr-ansl+1) ) );
  end;
end.