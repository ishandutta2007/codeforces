program problem3;

var n, m, a, b, i, k: longWord;

begin
  readln( n, a, b );

  if ( b = 0 ) and ( a > 0 ) and ( (n-a) = 1 ) then
  begin
    writeln( '-1' );
    halt;
  end;

  write( '1 ' );
  k := 1;
  m := a + b + 1;
  if ( b = 0 ) and ( a > 0 ) then
  begin
    write( '1 ' );
    inc( m );
  end;

  for i := 1 to b do
  begin
    k := k * 2;
    write( k, ' ' );
  end;
  for i := 1 to a do
  begin
    k := k + 1;
    write( k, ' ' );
  end;
  for i := (m+1) to n do
    write( '1 ' );
  writeln();
end.