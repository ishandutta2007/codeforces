program problem3;

var n, a, b, ca, cb, i: longWord;
    arr: array[1..100000] of longWord;

begin
  readln( n );
  for i := 1 to n do
    read( arr[i] );

  a := 0;
  b := 0;
  ca := 0;
  cb := 0;

  while ( (a+b) < n ) do
  begin
    while ( ca <= cb ) and ( (a+b) < n ) do
    begin
      inc( a );
      inc( ca, arr[a] );
    end;

    while ( cb < ca ) and ( (a+b) < n ) do
    begin
      inc( b );
      inc( cb, arr[n+1-b] );
    end;
  end;

  writeln( a, ' ', b );
end.