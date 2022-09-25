program problem5;
uses math;

type tRec = record
              h, i: longWord;
            end;
     tARec = record
               prev, next, cnt: longWord;
               arr: array[0..320] of tRec;
             end;

var k, a_i: longWord;
    int_arr: array[ 0..100000, -1..1 ] of longWord;
    a: array[0..20000] of tARec;

procedure balance( i1, i2: longWord );
var i, j: longWord;
begin
  if ( (a[i1].cnt+a[i2].cnt) <= 320 ) then
  begin
    for i := 1 to a[i2].cnt do
      a[i1].arr[ a[i1].cnt + i ] := a[i2].arr[i];
    a[i1].next := a[i2].next;
    a[ a[i2].next ].prev := i1;
    a[i1].cnt := ( a[i1].cnt + a[i2].cnt );
  end
  else
  begin
    if ( a[i1].cnt > a[i2].cnt ) then
    begin
      i := ( a[i1].cnt - a[i2].cnt ) div 2;
      for j := (a[i2].cnt+i) downTo (i+1) do
        a[i2].arr[j] := a[i2].arr[j-i];
      for j := 1 to i do
        a[i2].arr[j] := a[i1].arr[ a[i1].cnt - i + j ];
      inc( a[i2].cnt, i2 );
      dec( a[i1].cnt, i2 );
    end
    else
    begin
      i := ( a[i2].cnt - a[i1].cnt ) div 2;
      for j := 1 to i do
        a[i1].arr[ a[i1].cnt + j ] := a[i2].arr[j];
      for j := 1 to ( a[i2].cnt - i ) do
        a[i2].arr[j] := a[i2].arr[j+i];
      inc( a[i1].cnt, i );
      dec( a[i2].cnt, i );
    end;
  end;
end;

procedure proc( rec: tRec; t: longInt );
var i, j, i2, j2: longWord;
begin
  i := a[0].next;
  while ( a[i].next <> 0 ) and ( a[i].arr[ a[i].cnt ].h <= rec.h ) do
    i := a[i].next;
  j := 1;
  while ( j <= a[i].cnt ) and ( a[i].arr[j].h <= rec.h ) do
    inc(j);

  i2 := i;
  j2 := j;
  while ( true ) and ( j2 <= a[i2].cnt ) do
  begin
    int_arr[ a[i2].arr[j2].i ][t] := (rec.i-t);
    inc( j2 );
    if ( j2 > a[i2].cnt ) then
      if ( a[i2].next <> 0 ) then
      begin
        i2 := a[i2].next;
        j2 := 1;
      end
      else
        break;
  end;

  if ( j > 320 ) then
  begin
    inc( a_i );
    a[a_i].prev := i;
    a[a_i].next := 0;
    a[i].next := a_i;
    a[i].cnt := 160;
    a[a_i].cnt := 161;

    for i2 := 1 to 160 do
      a[a_i].arr[i2] := a[i].arr[i2+160];
    a[a_i].arr[161] := rec;
  end
  else
  begin
    a[i].arr[j] := rec;
    a[i].cnt := j;
    a[i].next := 0;
  end;

  if ( j < 160 ) and ( a[i].prev <> 0 ) then
    balance( a[i].prev, i );

  i := a[0].next;
  j := 1;
  while ( a[i].arr[j].h < ( rec.h - k ) ) do
  begin
    int_arr[ a[i].arr[j].i ][t] := (rec.i-t);

    inc(j);
    if ( j > a[i].cnt ) then
    begin
      i := a[i].next;
      j := 1;
    end;
  end;

  a[i].cnt := a[i].cnt - j + 1;
  for j2 := 1 to a[i].cnt do
    a[i].arr[j2] := a[i].arr[j2+j-1];

  a[i].prev := 0;
  a[0].next := i;
  if ( a[i].next <> 0 ) and ( a[i].cnt < 160 ) then
    balance( i, a[i].next );
end;

var n, i, i2, j, ans: longWord;
    arr, maxArr, ansArr: array[0..100000] of longWord;
    rec: tRec;

begin
  a_i := 1;
  a[0].next := 1;
  a[1].prev := 0;
  a[1].next := 0;
  a[1].cnt := 0;

  readln( n, k );
  for i := 1 to n do
    read( arr[i] );

  for i := 1 to n do
  begin
    rec.h := arr[i];
    rec.i := i;
    proc( rec, 1 );
    maxArr[i] := i;
  end;
  rec.h := 0;
  rec.i := (n+1);
  proc( rec, 1 );

  a_i := 1;
  a[0].next := 1;
  a[1].prev := 0;
  a[1].next := 0;
  a[1].cnt := 0;

  for i := n downTo 1 do
  begin
    rec.h := arr[i];
    rec.i := i;
    proc( rec, -1 );
  end;
  rec.h := 0;
  rec.i := 0;
  proc( rec, -1 );

  for i := 1 to n do
    maxArr[ int_arr[i][-1] ] := max( maxArr[ int_arr[i][-1] ], int_arr[i][1] );

  ans := 0;
  ansArr[0] := 0;
  for i := 1 to n do
    if ( ( maxArr[i] - i + 1 ) > ans ) then
    begin
      ans := ( maxArr[i] - i + 1 );
      ansArr[0] := 1;
      ansArr[1] := i;
    end
    else if ( ( maxArr[i] - i + 1 ) = ans ) then
    begin
      inc( ansArr[0] );
      ansArr[ ansArr[0] ] := i;
    end;

  writeln( ans, ' ', ansArr[0] );
  for i := 1 to ansArr[0] do
    writeln( ansArr[i], ' ', (ansArr[i]+ans-1) );
end.