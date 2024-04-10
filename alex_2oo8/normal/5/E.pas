program problem5;
type tRec = record
              h, cnt, next, prev: qWord;
            end;

var n, i, arr_i, a: longWord;
    arr: array[0..1000000] of tRec;
    ans: qWord;

begin
  arr_i := 0;
  arr[arr_i].h := 0;
  arr[arr_i].cnt := 0;

  readln( n );

  for i := 1 to n do
  begin
    read( a );
    if ( a = arr[arr_i].h ) then
      inc( arr[arr_i].cnt )
    else
    begin
      arr[arr_i].next := arr_i + 1;
      inc( arr_i );
      arr[arr_i].prev := arr_i - 1;

      arr[arr_i].h := a;
      arr[arr_i].cnt := 1;
    end;
  end;
  arr[arr_i].next := 1;
  arr[    1].prev := arr_i;

  if ( arr_i <> 1 ) and ( arr[arr_i].h = arr[1].h ) then
  begin
    arr[1].cnt := arr[1].cnt + arr[arr_i].cnt;
    arr[1].prev := arr[arr_i].prev;
    arr[ arr[arr_i].prev ].next := 1;
  end;

  ans := 0;
  i := 1;
  while ( true ) do
  begin
    if ( arr[i].next = i ) then
    begin
      inc( ans, ( ( arr[i].cnt * (arr[i].cnt-1) ) div 2 ) );
      break;
    end;

    if ( arr[i].h < arr[ arr[i].prev ].h ) and ( arr[i].h < arr[ arr[i].next ].h ) then
    begin
      if ( arr[i].next = arr[i].prev ) and ( arr[ arr[i].next ].cnt = 1 ) then
        inc( ans, ( ( arr[i].cnt * (arr[i].cnt+1) ) div 2 ) )
      else
        inc( ans, ( ( arr[i].cnt * (arr[i].cnt+3) ) div 2 ) );

      arr[ arr[i].prev ].next := arr[i].next;
      arr[ arr[i].next ].prev := arr[i].prev;
      i := arr[i].prev;
      if ( arr[i].next <> i ) and ( arr[i].h = arr[ arr[i].next ].h ) then
      begin
        arr[i].cnt := arr[i].cnt + arr[ arr[i].next ].cnt;
        arr[i].next := arr[ arr[i].next ].next;
        arr[ arr[i].next ].prev := i;
      end;

      i := arr[i].prev;
    end;

    i := arr[i].next;
  end;

  writeln( ans );
end.