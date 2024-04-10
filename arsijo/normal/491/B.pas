Program arsijo;
uses math;
Var a, b, i, j, n, c, h, m, x, y, minX, minY, maxX, maxY, dist, ans: longint;
    cax, cay, hax, hay: array [1..100000] of longint;
Begin
   Read(n, m);
   minX := n + m;
   minY := n + m;
   maxX := -minX;
   maxY := -minY;
   dist := n + m + 1;
   Read(c);
   for i:=1 to c do
   begin
       Read(x, y);
       minX := min(minX, x - y);
       minY := min(minY, x + y);
       maxX := max(maxX, x - y);
       maxY := max(maxY, x + y);
   end;
   Read(h);
   for i:=1 to h do
   begin
       Read(a, b);
       x := a - b;
       y := a + b;
       if (max(max(abs(minX - x), abs(maxX - x)), max(abs(minY - y), abs(maxY - y))) < dist) then
       begin
           dist := max(max(abs(minX - x), abs(maxX - x)), max(abs(minY - y), abs(maxY - y)));
            ans := i;
       end;
   end;
   WriteLn(dist);
   WriteLn(ans);
End.