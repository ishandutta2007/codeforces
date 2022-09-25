program problem1;

var n, i, j, m, k: longWord;
    D: qWord;

begin
  readln( n );

  for i := 1 to trunc( sqrt( 2 * n ) ) do
  begin
    if ( ( i * (i+1) div 2 ) > n ) then
      break;

    m := n - ( i * (i+1) div 2 );
    D := 1 + ( 8 * qWord(m) );
    if ( sqr( trunc( sqrt(D) ) ) = D ) then
    begin
      D := trunc( sqrt( D ) );
      k := ( D - 1 );
      if ( ( k mod 2 ) = 0 ) and ( k > 0 ) then
      begin
        writeln( 'YES' );
        halt;
      end;
    end;
  end;

  writeln( 'NO' );
end.