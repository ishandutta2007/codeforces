{$O-}
type game = record
  b, k: longint;
  end;

var
  a: array[1..4, 0..9] of boolean;
  b: array[1..10] of longint;
  c: array[1..10] of game;
  i, i1, i2, i3, i4, n, x, ddd, kol, z: longint;
  check: boolean;

function asd(a, b: longint): game;
var
  a1, b1: array[1..4] of longint;
  i, j: longint;
  z: game;

begin
  a1[1] := a mod 10;
  a := a div 10;
  a1[2] := a mod 10;
  a := a div 10;
  a1[3] := a mod 10;
  a := a div 10;
  a1[4] := a mod 10;
{//////////////////////}
  b1[1] := b mod 10;
  b := b div 10;
  b1[2] := b mod 10;
  b := b div 10;
  b1[3] := b mod 10;
  b := b div 10;
  b1[4] := b mod 10;
  z.b := 0;
  z.k := 0;
  for i := 1 to 4 do
    for j := 1 to 4 do
    begin
      if (a1[i] = b1[j]) and (i = j) then inc(z.b);
      if (a1[i] = b1[j]) and (i <> j) then inc(z.k);
    end;
  asd := z;  
end;

begin
  read(n);
  for i := 1 to n do
    read(b[i], c[i].b , c[i].k);
  ddd := -1;
  kol := 0;
  for i := 0 to 9 do
    for i1 := 0 to 9 do
      for i2 := 0 to 9 do
        for i3 := 0 to 9 do
        begin
          if (i <> i1) and (i <> i2) and (i <> i3) and
             (i1 <> i2) and (i1 <> i3) and (i2 <> i3) then
          begin
            check := true;
            z := i3 + i2 * 10 + i1 * 100 + i * 1000;
            for i4 := 1 to n do
              if (c[i4].k <> asd(z, b[i4]).k) or (c[i4].b <> asd(z, b[i4]).b) then
                check := false;

            if check then inc(kol);
            if (check) and (ddd = -1) then ddd := z;
          end;
        end;
  if kol > 1 then writeln('Need more data');
  if kol = 0 then writeln('Incorrect data');
  if (kol = 1) and (ddd >= 1000) then writeln(ddd);
  if (kol = 1) and (ddd < 1000) then writeln('0', ddd);
end.