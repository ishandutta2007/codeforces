program problem4;

type tRec = record
              k, t, previ, prevj, i, p: longWord;
              chr: char;
            end;
     tArr = array[ 0..1000, 0..1000 ] of tRec;

procedure writeAns( const arr: tArr; i, j: longWord );
begin
  if ( arr[i][j].p = 1 ) and ( ( arr[i][j].previ <> 0 ) or ( arr[i][j].prevj <> 0 ) ) then
    writeAns( arr, arr[i][j].previ, arr[i][j].prevj );

  if ( arr[i][j].t = 1 ) then
    writeln( 'INSERT ', arr[i][j].i, ' ', arr[i][j].chr )
  else if ( arr[i][j].t = 2 ) then
    writeln( 'DELETE ', arr[i][j].i )
  else if ( arr[i][j].t = 3 ) then
    writeln( 'REPLACE ', arr[i][j].i, ' ', arr[i][j].chr );

  if ( arr[i][j].p = 0 ) and ( ( arr[i][j].previ <> 0 ) or ( arr[i][j].prevj <> 0 ) ) then
    writeAns( arr, arr[i][j].previ, arr[i][j].prevj );
end;

var str1, str2: ansistring;
    i, j, k, n, m: longWord;
    arr: tArr;

begin
  readln( str1 );
  readln( str2 );

  n := length(str1);
  m := length(str2);

  arr[0][0].k := 0;
  for j := 1 to n do
  begin
    arr[0][j].k := j;
    arr[0][j].p := 0;
    arr[0][j].previ := 0;
    arr[0][j].prevj := j - 1;
    arr[0][j].t := 2;
    arr[0][j].i := j;
  end;

  for i := 1 to m do
  begin
    arr[i][0].k := i;
    arr[i][0].p := 1;
    arr[i][0].previ := i - 1;
    arr[i][0].prevj := 0;
    arr[i][0].t := 1;
    arr[i][0].i := i;
    arr[i][0].chr := str2[i];
    for j := 1 to n do
    begin
      arr[i][j].k := 1000000000;
      if ( str1[j] = str2[i] ) and ( arr[i-1][j-1].k < arr[i][j].k ) then
      begin
        arr[i][j].k := arr[i-1][j-1].k;
        arr[i][j].p := 1;
        arr[i][j].previ := i - 1;
        arr[i][j].prevj := j - 1;
        arr[i][j].t := 0;
      end
      else if ( (arr[i-1][j-1].k+1) < arr[i][j].k ) then
      begin
        arr[i][j].k := arr[i-1][j-1].k + 1;
        arr[i][j].p := 1;
        arr[i][j].previ := i - 1;
        arr[i][j].prevj := j - 1;
        arr[i][j].t := 3;
        arr[i][j].i := i;
        arr[i][j].chr := str2[i];
      end;
      if ( (arr[i][j-1].k+1) < arr[i][j].k ) then
      begin
        arr[i][j].k := arr[i][j-1].k + 1;
        arr[i][j].p := 0;
        arr[i][j].previ := i;
        arr[i][j].prevj := j - 1;
        arr[i][j].t := 2;
        arr[i][j].i := j;
      end;
      if ( (arr[i-1][j].k+1) < arr[i][j].k ) then
      begin
        arr[i][j].k := arr[i-1][j].k + 1;
        arr[i][j].p := 1;
        arr[i][j].previ := i - 1;
        arr[i][j].prevj := j;
        arr[i][j].t := 1;
        arr[i][j].i := i;
        arr[i][j].chr := str2[i];
      end;
    end;
  end;

  writeln( arr[m][n].k );
  writeAns( arr, m, n );
end.