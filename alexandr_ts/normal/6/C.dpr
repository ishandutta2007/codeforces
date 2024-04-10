var a:array[1..100000] of integer;
    n,i,j,k,m,p, alice, bob, sum, sumalice, sumbob : integer;
begin
 read(n);
 for i := 1 to n do
  begin
   read(a[i]);
   inc(sum, a[i]);
  end;
 if n = 1 then
  begin
   write('1 0');
   exit;
  end;
 alice := 1;
 bob := n;
 while (bob - alice > 1) and not((bob - alice = 2) and (a[bob] = 1) and (a[alice] = 1))do
  begin
   dec(a[alice]);
   if a[alice] = 0 then
    begin
     inc(alice);
     inc(sumalice);
    end;
   dec(a[bob]);
   if a[bob] = 0 then
    begin
     dec(bob);
     inc(sumbob);
    end;
  end;
 if sumalice + sumbob + 2 = n then
  write(sumalice + 1,' ', sumbob + 1)
 else
  write(sumalice + 2,' ', sumbob + 1);
end.