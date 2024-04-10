program problem3;

var k, i, arr_i: longWord;
    ans: qWord;
    arr: array[1..1000001] of qWord;
    str: ansistring;

begin
  arr_i := 1;
  arr[ arr_i ] := 0;

  readln( k );
  readln( str );
  for i := 1 to length( str ) do
  begin
    if ( str[i] = '0' ) then
      inc( arr[ arr_i ] )
    else
    begin
      if ( k = 0 ) then
        ans := ans + ( ( arr[ arr_i ] * ( arr[ arr_i ] + 1 ) ) div 2 )
      else if ( arr_i > k ) then
        ans := ans + ( ( arr[arr_i] + 1 ) * ( arr[ arr_i - k ] + 1 ) );

      inc( arr_i );
      arr[ arr_i ] := 0;
    end;
  end;
  if ( k = 0 ) then
    ans := ans + ( ( arr[ arr_i ] * ( arr[ arr_i ] + 1 ) ) div 2 )
  else if ( arr_i > k ) then
    ans := ans + ( ( arr[arr_i] + 1 ) * ( arr[ arr_i - k ] + 1 ) );

  writeln( ans );
end.