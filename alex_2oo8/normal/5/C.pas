program problem3;
const l = '(';
      r = ')';

var str: ansistring;
    i, max, cnt, arr_i: longWord;
    arr: array[ 1..1000000, l..r ] of longWord;

begin
  max := 0;
  cnt := 1;
  arr_i := 1;
  arr[arr_i][l] := 0;
  arr[arr_i][r] := 0;

  readln( str );
  for i := 1 to length(str) do
  begin
    if ( str[i] = l ) then
      if ( arr[arr_i][r] = 0 ) then
        inc( arr[arr_i][l] )
      else
      begin
        inc( arr_i );
        arr[arr_i][l] := 1;
        arr[arr_i][r] := 0;
      end
    else
    begin
      if ( arr[arr_i][r] = 0 ) and ( arr[arr_i][l] > 0 ) then
      begin
        dec( arr[ arr_i ][l] );
        if ( arr[ arr_i ][l] > 0 ) then
          inc( arr_i );
        arr[ arr_i ][l] := 1;
        arr[ arr_i ][r] := 1;

        if ( arr_i > 1 ) and ( arr[arr_i-1][r] > 0 ) then
        begin
          dec( arr_i );
          inc( arr[arr_i][l] );
          inc( arr[arr_i][r] );
        end;

        if ( ( arr[arr_i][l] + arr[arr_i][r] ) > max ) then
        begin
          max := arr[arr_i][l] + arr[arr_i][r];
          cnt := 1;
        end
        else if ( ( arr[arr_i][l] + arr[arr_i][r] ) = max ) then
          inc( cnt );

      end
      else if ( arr_i > 1 ) and ( arr[arr_i][r] > 0 ) then
      begin
        dec( arr[arr_i-1][l] );
        if ( arr[arr_i-1][l] = 0 ) then
        begin
          arr[arr_i-1] := arr[arr_i];
          dec( arr_i );
        end;
        inc( arr[arr_i][l] );
        inc( arr[arr_i][r] );

        if ( arr_i > 1 ) and ( arr[arr_i-1][r] > 0 ) then
        begin
          dec( arr_i );
          inc( arr[arr_i][l], arr[arr_i+1][l] );
          inc( arr[arr_i][r], arr[arr_i+1][l] );
        end;

        if ( ( arr[arr_i][l] + arr[arr_i][r] ) > max ) then
        begin
          max := arr[arr_i][l] + arr[arr_i][r];
          cnt := 1;
        end
        else if ( ( arr[arr_i][l] + arr[arr_i][r] ) = max ) then
          inc( cnt );
      end
      else
      begin
        arr_i := 1;
        arr[arr_i][l] := 0;
        arr[arr_i][r] := 0;
      end;
    end;
  end;

  writeln( max, ' ', cnt );
end.