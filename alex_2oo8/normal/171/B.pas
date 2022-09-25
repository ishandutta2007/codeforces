program problem2;

var a, ans, k: longWord;

begin
  readln( a );

  ans := 1;
  dec( a );
  k := 12;

  while ( a > 0 ) do
  begin
    ans := ans + k;
    k := k + 12;
    dec( a );
  end;

  writeln( ans );
end.