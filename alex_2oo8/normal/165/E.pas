program problem5;

var ans: array[0..5000000] of longWord;

procedure add( m, a: longWord );
var i: longWord;
begin
  if ( ans[m] > 0 ) then
    exit();

  ans[m] := a;
  for i := 0 to 21 do
    if ( ( m and (1 shl i) ) > 0 ) then
      add( ( m - (1 shl i) ), a );
end;

var n, i, m: longWord;
    a: array[1..1000000] of longWord;

begin
  fillchar( ans, sizeOf(ans), 0 );
  m := ( 1 shl 22 ) - 1;

  readln( n );
  for i := 1 to n do
  begin
    read( a[i] );

    add( (a[i] xor m), a[i] );
  end;

  for i := 1 to n do
    if ( ans[ a[i] ] = 0 ) then
      write( '-1 ' )
    else
      write( ans[ a[i] ], ' ' );
end.