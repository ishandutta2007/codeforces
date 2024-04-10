program problem2;

var t, n, i, j, i2, k: longWord;
    x: int64;
    str: string[6];
    arr: array[1..100] of longWord;

begin
  k := 0;

  readln( t, n );
  for i := 1 to n do
    arr[i] := 0;

  for i2 := 1 to t do
  begin
    read( str );
    if ( str = 'alloc ' ) then
    begin
      readln( x );
      i := 1;
      while ( i <= n ) and ( arr[i] > 0 ) do
        inc( i );
      j := i;
      while ( j <= n ) and ( ( j - i + 1 ) < x ) do
      begin
        while ( j <= n ) and ( ( j - i + 1 ) < x ) and ( arr[j+1] = 0 ) do
          inc( j );

        if ( ( j - i + 1 ) < x ) then
        begin
          i := j + 1;
          while ( i <= n ) and ( arr[i] > 0 ) do
            inc( i );
          j := i;
        end;
      end;

      if ( i > n ) or ( j > n ) or ( ( j - i + 1 ) < x ) then
        writeln( 'NULL' )
      else
      begin
        inc( k );
        writeln( k );
        for i := i to j do
          arr[i] := k;
      end;
    end
    else if ( str = 'erase ' ) then
    begin
      readln( x );
      i := 1;
      while ( i <= n ) and ( arr[i] <> x ) do
        inc( i );

      if ( i > n ) or ( x < 1 ) then
        writeln( 'ILLEGAL_ERASE_ARGUMENT' )
      else
        while ( i <= n ) and ( arr[i] = x ) do
        begin
          arr[i] := 0;
          inc( i );
        end;
    end
    else
    begin
      readln( str );
      i := 1;
      j := 2;
      while ( i <= n ) and ( j <= n ) do
      begin
        while ( i <= n ) and ( arr[i] <> 0 ) do
          inc( i );
        j := i + 1;
        while ( j <= n ) and ( arr[j] = 0 ) do
          inc( j );

        while ( i <= n ) and ( j <= n ) and ( arr[j] <> 0 ) do
        begin
          arr[i] := arr[j];
          arr[j] := 0;
          inc( i );
          inc( j );
        end;
      end;
    end;
  end;
end.