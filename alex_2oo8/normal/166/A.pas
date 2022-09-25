program problem1;
type tArr = array[1..50] of record
                             p, t: byte;
                           end;

procedure sort( var arr: tArr; cnt: byte );
var i, j, tp, tt: longWord;
begin
  for i := 1 to cnt do
    for j := (i+1) to cnt do
    begin
      if ( arr[j].p > arr[i].p ) or ( ( arr[j].p = arr[i].p ) and ( arr[j].t < arr[i].t ) ) then
      begin
        tp := arr[i].p;
        tt := arr[i].t;
        arr[i].t := arr[j].t;
        arr[i].p := arr[j].p;
        arr[j].t := tt;
        arr[j].p := tp;
      end;
    end;
end;

var n, k: byte;
    commands: tArr;
    i, ans: longWord;

begin
  readln( n, k );
  for i := 1 to n do
    readln( commands[i].p, commands[i].t );

  sort( commands, n );

  ans := 1;
  i := k;
  while ( i > 1 ) and ( commands[i].p = commands[i-1].p ) and ( commands[i].t = commands[i-1].t ) do
    dec(i);
  while ( i < n ) and ( commands[i].p = commands[i+1].p ) and ( commands[i].t = commands[i+1].t ) do
  begin
    inc( ans );
    inc( i );
  end;
  writeln( ans );
end.