program problem2;
uses math;

type tRec = record
             n: longWord;
             h: qWord;
           end;
     tArr = array[1..1000] of tRec;

procedure qsort( var arr: tArr; l, r: longWord );
var i, j: longWord;
    med, t: tRec;
begin
  if ( r > l ) then
  begin
    med := arr[ (l+r) div 2 ];
    i := l;
    j := r;
    while ( i <= j ) do
    begin
      while ( arr[i].h < med.h ) or ( ( arr[i].h = med.h ) and ( arr[i].n > med.n ) ) do
        inc( i );
      while ( arr[j].h > med.h ) or ( ( arr[j].h = med.h ) and ( arr[j].n < med.n ) ) do
        dec( j );

      if ( i <= j ) then
      begin
        t := arr[i];
        arr[i] := arr[j];
        arr[j] := t;

        inc( i );
        dec( j );
      end;
    end;

    qsort( arr, l, j );
    qsort( arr, i, r );
  end;
end;

var n, t1, t2, k, u, v, i: longWord;
    arr: tArr;

begin
    readln( n, t1, t2, k );
    for i := 1 to n do
    begin
        readln( u, v );
        arr[i].n := i;
        arr[i].h := max( ( ( u * t1 * ( 100 - k ) ) + 100 * v * t2 ), 
                         ( ( v * t1 * ( 100 - k ) ) + 100 * u * t2 ) );
    end;
    
    qsort( arr, 1, n );
    
    for i := n downTo 1 do
        writeln( arr[i].n, ' ', ( arr[i].h / 100 ):0:2 );
end.