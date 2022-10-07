var
  a: array[0..1000] of longint;
  c, n, k, i, sum: longint;


begin
   read(n, k, c);
  a[0] := 0;
  for i := 1 to c do
    read(a[i]);

  inc(c);  
  a[c] := n + 1;

  sum := 0;
  for i := 0 to c - 1 do
    sum := (a[i + 1] - a[i] - 1) div k  + sum;


  writeln(sum + c - 1);




end.